from CRABClient.UserUtilities import config
config = config()


config.General.requestName = 'modKBMTF_ScoutingSelection_2025_398632_50'
config.General.workArea = '/eos/user/f/flarover/crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'kbmtFlatTableProducerSlow_cfg.py'
config.JobType.allowUndistributedCMSSW = True

#config.JobType.numCores = 2
#config.JobType.maxMemoryMB = 4000

#config.Data.inputDataset = "/L1Scouting/Run2024G-v1/L1SCOUT"
config.Data.inputDataset = "/L1ScoutingSelection/Run2025G-v1/L1SCOUT"
config.Data.runRange = '398632-398650'
config.Data.inputDBS = "global"
config.Data.splitting = 'Automatic'
config.Data.lumiMask = 'https://cms-service-dqmdc.web.cern.ch/CAF/certification/Collisions25/Cert_Collisions2025_391658_398903_Muon.json'
#config.Data.outLFNDirBase = '/store/group/cmst3/group/slowmuons/Mu8Skim/'
config.Data.outLFNDirBase = '/store/group/cmst3/group/slowmuons/AnalysisHSCP2025_Francesco/CRAB_DATA'
config.Data.publication = False
config.Site.storageSite = 'T2_CH_CERN'


