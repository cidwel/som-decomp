.setcpu "65816"
.segment "CODE"
.org $E3DD
.include "boss_state_command_macros.inc"
boss_state_pc_c2e3dd:
    boss_state_set98_40
boss_state_pc_c2e3de:
    boss_state_c0_006c $0038
boss_state_pc_c2e3e1:
    boss_state_anim $014C
boss_state_pc_c2e3e4:
    boss_state_duration14 $0018
boss_state_pc_c2e3e7:
    boss_state_end
boss_state_pc_c2e3e8:
    boss_state_clr98_40
boss_state_pc_c2e3e9:
    boss_state_c0_006c $0038
boss_state_pc_c2e3ec:
    boss_state_anim $014C
boss_state_pc_c2e3ef:
    boss_state_duration14 $0018
boss_state_pc_c2e3f2:
    boss_state_end
boss_state_pc_c2e3f3:
    boss_state_set98_40
boss_state_pc_c2e3f4:
    boss_state_c0_006c $0038
boss_state_pc_c2e3f7:
    boss_state_anim $0143
boss_state_pc_c2e3fa:
    boss_state_duration14 $0018
boss_state_pc_c2e3fd:
    boss_state_end
boss_state_pc_c2e3fe:
    boss_state_clr98_40
boss_state_pc_c2e3ff:
    boss_state_c0_006c $0038
boss_state_pc_c2e402:
    boss_state_anim $0143
boss_state_pc_c2e405:
    boss_state_duration14 $0018
boss_state_pc_c2e408:
    boss_state_end
boss_state_pc_c2e409:
    boss_state_spell $0112
boss_state_pc_c2e40c:
    boss_state_jump $E43D
boss_state_pc_c2e40f:
    boss_state_spell $0114
boss_state_pc_c2e412:
    boss_state_jump $E43D
boss_state_pc_c2e415:
    boss_state_spell $0016
boss_state_pc_c2e418:
    boss_state_jump $E43D
boss_state_pc_c2e41b:
    boss_state_spell $0113
boss_state_pc_c2e41e:
    boss_state_jump $E430
boss_state_pc_c2e421:
    boss_state_spell $000C
boss_state_pc_c2e424:
    boss_state_jump $E43D
boss_state_pc_c2e427:
    boss_state_spell $0010
boss_state_pc_c2e42a:
    boss_state_jump $E43D
boss_state_pc_c2e42d:
    boss_state_spell $000E
boss_state_pc_c2e430:
    boss_state_c0_006c $0038
boss_state_pc_c2e433:
    boss_state_anim $0144
boss_state_pc_c2e436:
    boss_state_f48 $67AE
boss_state_pc_c2e439:
    boss_state_duration14 $000C
boss_state_pc_c2e43c:
    boss_state_end
boss_state_pc_c2e43d:
    boss_state_c0_006c $0038
boss_state_pc_c2e440:
    boss_state_anim $0147
boss_state_pc_c2e443:
    boss_state_duration14 $000C
boss_state_pc_c2e446:
    boss_state_end
boss_state_pc_c2e447:
    boss_state_spawn $0011, $000E, $0006
boss_state_pc_c2e44b:
    boss_state_c0_006c $0011
boss_state_pc_c2e44e:
    boss_state_jump $E458
boss_state_pc_c2e451:
    boss_state_spawn $0008, $000E, $0006
boss_state_pc_c2e455:
    boss_state_c0_006c $0008
boss_state_pc_c2e458:
    boss_state_c0_006c $0038
boss_state_pc_c2e45b:
    boss_state_anim $0145
boss_state_pc_c2e45e:
    boss_state_duration14 $000C
boss_state_pc_c2e461:
    boss_state_end
boss_state_pc_c2e462:
    boss_state_anim $0146
boss_state_pc_c2e465:
    boss_state_f4a $34B9
boss_state_pc_c2e468:
    boss_state_end
boss_state_pc_c2e469:
    boss_state_store $007E, $0010
boss_state_pc_c2e46e:
    boss_state_jump $E496
boss_state_pc_c2e471:
    boss_state_store $007E, $0011
boss_state_pc_c2e476:
    boss_state_jump $E496
boss_state_pc_c2e479:
    boss_state_store $007E, $0012
boss_state_pc_c2e47e:
    boss_state_jump $E496
boss_state_pc_c2e481:
    boss_state_store $007E, $0013
boss_state_pc_c2e486:
    boss_state_jump $E496
boss_state_pc_c2e489:
    boss_state_store $007E, $0014
boss_state_pc_c2e48e:
    boss_state_jump $E496
boss_state_pc_c2e491:
    boss_state_store $007E, $0015
boss_state_pc_c2e496:
    boss_state_c0_006c $0038
boss_state_pc_c2e499:
    boss_state_callnative $67D1
boss_state_pc_c2e49c:
    boss_state_speed90 $69B9
boss_state_pc_c2e49f:
    boss_state_f4a $69F7
boss_state_pc_c2e4a2:
    boss_state_end
boss_state_pc_c2e4a3:
    boss_state_c0_006c $0038
boss_state_pc_c2e4a6:
    boss_state_store $007E, $0000
boss_state_pc_c2e4ab:
    boss_state_callnative $67D1
boss_state_pc_c2e4ae:
    boss_state_speed90 $69B9
boss_state_pc_c2e4b1:
    boss_state_f4a $69F7
boss_state_pc_c2e4b4:
    boss_state_end
boss_state_pc_c2e4b5:
    boss_state_anim $014B
boss_state_pc_c2e4b8:
    boss_state_store $0066, $0080
boss_state_pc_c2e4bd:
    boss_state_callnative $68FB
boss_state_pc_c2e4c0:
    boss_state_end
boss_state_pc_c2e4c1:
    boss_state_anim $014B
boss_state_pc_c2e4c4:
    boss_state_store $0066, $0081
boss_state_pc_c2e4c9:
    boss_state_store $0082, $0000
boss_state_pc_c2e4ce:
    boss_state_end
boss_state_pc_c2e4cf:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $001E
boss_state_pc_c2e4dc:
    boss_state_store $0066, $0081
boss_state_pc_c2e4e1:
    boss_state_store $0082, $0000
boss_state_pc_c2e4e6:
    boss_state_store $0070, $0001
boss_state_pc_c2e4eb:
    boss_state_speed90 $36BC
boss_state_pc_c2e4ee:
    boss_state_duration14 $0006
boss_state_pc_c2e4f1:
    boss_state_end
boss_state_pc_c2e4f2:
    boss_state_store $002B, $0080
boss_state_pc_c2e4f7:
    boss_state_store $0032, $00D0
boss_state_pc_c2e4fc:
    boss_state_store $007E, $0020
boss_state_pc_c2e501:
    boss_state_anim $014B
boss_state_pc_c2e504:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $FFE2
boss_state_pc_c2e511:
    boss_state_c0_006c $0039
boss_state_pc_c2e514:
    boss_state_speed90 $69B9
boss_state_pc_c2e517:
    boss_state_f4a $69F7
boss_state_pc_c2e51a:
    boss_state_end
boss_state_pc_c2e51b:
    boss_state_store $002B, $0150
boss_state_pc_c2e520:
    boss_state_store $0032, $00E0
boss_state_pc_c2e525:
    boss_state_store $007E, $0021
boss_state_pc_c2e52a:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $FFE2
boss_state_pc_c2e537:
    boss_state_c0_006c $0039
boss_state_pc_c2e53a:
    boss_state_speed90 $69B9
boss_state_pc_c2e53d:
    boss_state_f4a $69F7
boss_state_pc_c2e540:
    boss_state_end
boss_state_pc_c2e541:
    boss_state_call30e3 $004A
boss_state_pc_c2e544:
    boss_state_store $0070, $0000
boss_state_pc_c2e549:
    boss_state_c18003 $BCEF
boss_state_pc_c2e54c:
    boss_state_duration14 $0001
boss_state_pc_c2e54f:
    boss_state_end
boss_state_pc_c2e550:
    boss_state_store $002B, $00F0
boss_state_pc_c2e555:
    boss_state_store $0032, $0120
boss_state_pc_c2e55a:
    boss_state_store $007E, $0020
boss_state_pc_c2e55f:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $FFE2
boss_state_pc_c2e56c:
    boss_state_c0_006c $0039
boss_state_pc_c2e56f:
    boss_state_speed90 $69B9
boss_state_pc_c2e572:
    boss_state_f4a $69F7
boss_state_pc_c2e575:
    boss_state_end
boss_state_pc_c2e576:
    boss_state_store $002B, $0170
boss_state_pc_c2e57b:
    boss_state_store $0032, $0120
boss_state_pc_c2e580:
    boss_state_store $007E, $0021
boss_state_pc_c2e585:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $FFE2
boss_state_pc_c2e592:
    boss_state_c0_006c $0039
boss_state_pc_c2e595:
    boss_state_speed90 $69B9
boss_state_pc_c2e598:
    boss_state_f4a $69F7
boss_state_pc_c2e59b:
    boss_state_end
boss_state_pc_c2e59c:
    boss_state_store $007E, $0021
boss_state_pc_c2e5a1:
    boss_state_jump $E496
boss_state_pc_c2e5a4:
    boss_state_store $007E, $0020
boss_state_pc_c2e5a9:
    boss_state_jump $E496
boss_state_pc_c2e5ac:
    boss_state_end
