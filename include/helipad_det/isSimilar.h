int isSimilar(std::vector<float> ListSignatures){
	
	
	float a = 0.19, b = 0.04, c = 0.08, d = 0.08;
	float tolerance=0.05;
	int ListSignaturesSize = ListSignatures.size();

	int StartIndex=-1;

	for (int i=0;i<ListSignaturesSize;i++){
		if (ListSignatures.at(i)==0) continue;
		else {
			int ZeroLength=0;
			int Index = i;
			while (ListSignatures.at(Index+ZeroLength)==0) ZeroLength++;
			if ((ZeroLength < (5.1)*ListSignaturesSize/26) && (ZeroLength > (4.9)*ListSignaturesSize/26)){
				StartIndex=i;
				break;
			} 
		}
	}

	if (StartIndex==-1) return 0;

	std::vector<float> UpdatedListSignatures;

	int Segments[12];
	int CountSegments=0;

	for (int i=StartIndex;i<ListSignaturesSize;i++) UpdatedListSignatures.push_back(ListSignatures.at(i));
	for (int i=0;i<StartIndex;i++) UpdatedListSignatures.push_back(ListSignatures.at(i));

	for (int i=0;i<ListSignaturesSize;i++){
		if (UpdatedListSignatures.at(i)==0) continue;
		
		if (CountSegments > 12) return 0;
		
		int Length=1;
		while (ListSignatures.at(i+Length)==0) Length++;
		Segments[CountSegments]=Length;
		CountSegments++;
	}


	if (abs(Segments[0]-(0.19*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[1]-(0.04*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[2]-(0.08*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[3]-(0.08*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[4]-(0.08*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[5]-(0.04*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[6]-(0.19*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[7]-(0.04*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[8]-(0.08*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[9]-(0.08*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[10]-(0.08*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;
	if (abs(Segments[11]-(0.04*ListSignaturesSize)) > (tolerance*ListSignaturesSize)) return 0;

	return 1;


}