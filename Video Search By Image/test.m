function video2pic( videoFile, outputPath, picFormat )
if nargin('video2pic')==3
    videoFile = input('Input full video path:', 's');
    outputPath = input('Input video output path[Default is under the video path]:', 's');
    if isempty(outputPath)
        outputPath = videoFile(1, 1:find(videoFile=='\', 1, 'last')-1);
    end
    picFormat = input('Input output pic format[JPG by default]:');
    if isempty(picFormat)
        picFormat = 'JPG';
    end
end


videoObject = VideoReader(videoFile);
nof=input('Enter the gap between each frame:');
numFrames = get(videoObject, 'numberOfFrames');
fileName = get(videoObject, 'Name');
outputPath = fullfile(outputPath, fileName(1, 1:find(fileName=='.', 1, 'last')-1));
numOrder = max(4, size(int2str(numFrames), 2));
mkdir(outputPath);

indexFrame = [1 1];
frameLimit = 100;
 k=1;
while indexFrame(1, 1) <= numFrames

    indexFrame(1, 2) = min(numFrames, indexFrame(1, 1) + frameLimit);
    frameAll = read(videoObject, indexFrame);
        
    for i = indexFrame(1, 1):nof:indexFrame(1, 2)   
        imgFrame = frameAll(:,:,:,i - indexFrame(1, 1) + 1);
        saveFormat = strcat('%s\\%s_%0', int2str(numOrder), 'd.%s');
        picName = sprintf(saveFormat, outputPath, fileName, k, picFormat);
        imwrite(imgFrame, picName);
        disp(picName);
        k=k+1;
    end
    indexFrame(1, 1) = indexFrame(1, 2) + 1;
end

end



