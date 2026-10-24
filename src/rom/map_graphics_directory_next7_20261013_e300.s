; Typed transfer descriptors only; no pointed tile graphics.
.setcpu "65816"
.segment "CODE"
.org $E300
.macro map_graphics_transfer format_id, first_unit, count_minus_one
    .word (format_id << 13) | first_unit
    .byte count_minus_one
.endmacro
map_graphics_transfer_e300:
    map_graphics_transfer 6, $0800, $2F
map_graphics_transfer_e303:
    map_graphics_transfer 6, $081A, $3F
map_graphics_transfer_e306:
    map_graphics_transfer 6, $0851, $4F
map_graphics_transfer_e309:
    map_graphics_transfer 6, $08A0, $1F
map_graphics_transfer_e30c:
    map_graphics_transfer 6, $08B8, $1F
map_graphics_transfer_e30f:
    map_graphics_transfer 4, $0000, $0F
map_graphics_transfer_e312:
    map_graphics_transfer 6, $09B3, $0F
map_graphics_transfer_e315:
    map_graphics_transfer 6, $09BF, $0F
map_graphics_transfer_e318:
    map_graphics_transfer 6, $09CF, $0F
map_graphics_transfer_e31b:
    map_graphics_transfer 4, $0010, $2F
map_graphics_transfer_e31e:
    map_graphics_transfer 6, $09DB, $0F
map_graphics_transfer_e321:
    map_graphics_transfer 6, $09DF, $1F
map_graphics_transfer_e324:
    map_graphics_transfer 6, $08CF, $1F
map_graphics_transfer_e327:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e32a:
    map_graphics_transfer 4, $0034, $01
map_graphics_transfer_e32d:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e330:
    map_graphics_transfer 4, $0036, $0E
map_graphics_transfer_e333:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e336:
    map_graphics_transfer 4, $0045, $0B
map_graphics_transfer_e339:
    map_graphics_transfer 6, $09FA, $1F
map_graphics_transfer_e33c:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e33f:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e342:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e345:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e348:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e34b:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e34e:
    map_graphics_transfer 6, $173A, $1F
map_graphics_transfer_e351:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_e354:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e357:
    map_graphics_transfer 6, $0AF1, $0F
map_graphics_transfer_e35a:
    map_graphics_transfer 6, $0AFA, $2E
map_graphics_transfer_e35d:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e360:
    map_graphics_transfer 6, $08CF, $1F
map_graphics_transfer_e363:
    map_graphics_transfer 6, $08E8, $3F
map_graphics_transfer_e366:
    map_graphics_transfer 6, $0924, $1F
map_graphics_transfer_e369:
    map_graphics_transfer 6, $093F, $7F
map_graphics_transfer_e36c:
    map_graphics_transfer 4, $0000, $0F
map_graphics_transfer_e36f:
    map_graphics_transfer 6, $09B3, $0F
map_graphics_transfer_e372:
    map_graphics_transfer 6, $09BF, $0F
map_graphics_transfer_e375:
    map_graphics_transfer 6, $09CF, $0F
map_graphics_transfer_e378:
    map_graphics_transfer 4, $0010, $2F
map_graphics_transfer_e37b:
    map_graphics_transfer 6, $09DB, $0F
map_graphics_transfer_e37e:
    map_graphics_transfer 6, $09DF, $3F
map_graphics_transfer_e381:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e384:
    map_graphics_transfer 4, $0034, $01
map_graphics_transfer_e387:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e38a:
    map_graphics_transfer 4, $0036, $0E
map_graphics_transfer_e38d:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e390:
    map_graphics_transfer 4, $0045, $0B
map_graphics_transfer_e393:
    map_graphics_transfer 6, $09FA, $1F
map_graphics_transfer_e396:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e399:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e39c:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e39f:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e3a2:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e3a5:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e3a8:
    map_graphics_transfer 6, $0AA6, $1F
map_graphics_transfer_e3ab:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_e3ae:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e3b1:
    map_graphics_transfer 6, $0AF1, $0F
map_graphics_transfer_e3b4:
    map_graphics_transfer 6, $0AFA, $2E
map_graphics_transfer_e3b7:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e3ba:
    map_graphics_transfer 6, $08CF, $1F
map_graphics_transfer_e3bd:
    map_graphics_transfer 6, $08E8, $3F
map_graphics_transfer_e3c0:
    map_graphics_transfer 6, $0924, $1F
map_graphics_transfer_e3c3:
    map_graphics_transfer 6, $093F, $7F
map_graphics_transfer_e3c6:
    map_graphics_transfer 6, $0B10, $4F
map_graphics_transfer_e3c9:
    map_graphics_transfer 6, $0B55, $AF
map_graphics_transfer_e3cc:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e3cf:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e3d2:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e3d5:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e3d8:
    map_graphics_transfer 4, $0034, $01
map_graphics_transfer_e3db:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e3de:
    map_graphics_transfer 4, $0036, $0E
map_graphics_transfer_e3e1:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e3e4:
    map_graphics_transfer 4, $0045, $0B
map_graphics_transfer_e3e7:
    map_graphics_transfer 6, $09FA, $1F
map_graphics_transfer_e3ea:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e3ed:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_e3f0:
    map_graphics_transfer 6, $09BF, $0F
map_graphics_transfer_e3f3:
    map_graphics_transfer 6, $09CF, $0F
map_graphics_transfer_e3f6:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e3f9:
    map_graphics_transfer 6, $09B3, $0F
map_graphics_transfer_e3fc:
    map_graphics_transfer 6, $0AFA, $1F
map_graphics_transfer_e3ff:
    map_graphics_transfer 6, $0AF1, $0E
map_graphics_transfer_e402:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e405:
    map_graphics_transfer 6, $1B3D, $1F
map_graphics_transfer_e408:
    map_graphics_transfer 6, $1B5B, $5F
map_graphics_transfer_e40b:
    map_graphics_transfer 6, $1F97, $4F
map_graphics_transfer_e40e:
    map_graphics_transfer 6, $1FE6, $6F
map_graphics_transfer_e411:
    map_graphics_transfer 6, $0800, $FF
map_graphics_transfer_e414:
    map_graphics_transfer 6, $1174, $1F
map_graphics_transfer_e417:
    map_graphics_transfer 5, $0336, $1F
map_graphics_transfer_e41a:
    map_graphics_transfer 6, $1193, $DE
map_graphics_transfer_e41d:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e420:
    map_graphics_transfer 6, $0BC5, $1F
map_graphics_transfer_e423:
    map_graphics_transfer 6, $0BE1, $1F
map_graphics_transfer_e426:
    map_graphics_transfer 6, $0BF3, $1F
map_graphics_transfer_e429:
    map_graphics_transfer 6, $0C09, $1F
map_graphics_transfer_e42c:
    map_graphics_transfer 6, $0C25, $1F
map_graphics_transfer_e42f:
    map_graphics_transfer 6, $0C42, $1F
map_graphics_transfer_e432:
    map_graphics_transfer 6, $0C5D, $7F
map_graphics_transfer_e435:
    map_graphics_transfer 6, $0CAF, $1F
map_graphics_transfer_e438:
    map_graphics_transfer 6, $0CBC, $FF
map_graphics_transfer_e43b:
    map_graphics_transfer 6, $0CBC, $FE
map_graphics_transfer_e43e:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e441:
    map_graphics_transfer 6, $0CEE, $4F
map_graphics_transfer_e444:
    map_graphics_transfer 4, $00F7, $1F
map_graphics_transfer_e447:
    map_graphics_transfer 6, $0AA6, $1F
map_graphics_transfer_e44a:
    map_graphics_transfer 6, $0800, $7F
map_graphics_transfer_e44d:
    map_graphics_transfer 6, $09B3, $0F
map_graphics_transfer_e450:
    map_graphics_transfer 6, $09BF, $0F
map_graphics_transfer_e453:
    map_graphics_transfer 6, $09CF, $0F
map_graphics_transfer_e456:
    map_graphics_transfer 4, $0010, $2F
map_graphics_transfer_e459:
    map_graphics_transfer 6, $09DB, $0F
map_graphics_transfer_e45c:
    map_graphics_transfer 6, $09DF, $3F
map_graphics_transfer_e45f:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e462:
    map_graphics_transfer 4, $0034, $01
map_graphics_transfer_e465:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e468:
    map_graphics_transfer 4, $0036, $0E
map_graphics_transfer_e46b:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e46e:
    map_graphics_transfer 4, $0045, $0B
map_graphics_transfer_e471:
    map_graphics_transfer 6, $09FA, $1F
map_graphics_transfer_e474:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e477:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e47a:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e47d:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e480:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e483:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e486:
    map_graphics_transfer 6, $08CF, $1F
map_graphics_transfer_e489:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_e48c:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e48f:
    map_graphics_transfer 4, $0000, $0F
map_graphics_transfer_e492:
    map_graphics_transfer 6, $0AFA, $2E
map_graphics_transfer_e495:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e498:
    map_graphics_transfer 6, $0D3A, $8F
map_graphics_transfer_e49b:
    map_graphics_transfer 6, $0800, $6F
map_graphics_transfer_e49e:
    map_graphics_transfer 6, $0800, $FF
map_graphics_transfer_e4a1:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e4a4:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e4a7:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e4aa:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e4ad:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e4b0:
    map_graphics_transfer 6, $0BC5, $BE
map_graphics_transfer_e4b3:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e4b6:
    map_graphics_transfer 6, $1174, $1F
map_graphics_transfer_e4b9:
    map_graphics_transfer 5, $0336, $1F
map_graphics_transfer_e4bc:
    map_graphics_transfer 6, $1193, $4F
map_graphics_transfer_e4bf:
    map_graphics_transfer 6, $0DAE, $6F
map_graphics_transfer_e4c2:
    map_graphics_transfer 4, $0355, $2F
map_graphics_transfer_e4c5:
    map_graphics_transfer 5, $0360, $0F
map_graphics_transfer_e4c8:
    map_graphics_transfer 6, $0DCC, $2F
map_graphics_transfer_e4cb:
    map_graphics_transfer 6, $11DC, $1D
map_graphics_transfer_e4ce:
    map_graphics_transfer 6, $1FFF, $01
map_graphics_transfer_e4d1:
    map_graphics_transfer 6, $0800, $4F
map_graphics_transfer_e4d4:
    map_graphics_transfer 4, $020A, $1F
map_graphics_transfer_e4d7:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e4da:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e4dd:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e4e0:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e4e3:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e4e6:
    map_graphics_transfer 6, $0A8C, $5F
map_graphics_transfer_e4e9:
    map_graphics_transfer 6, $0AD5, $5E
map_graphics_transfer_e4ec:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e4ef:
    map_graphics_transfer 4, $015D, $4F
map_graphics_transfer_e4f2:
    map_graphics_transfer 4, $019C, $4F
map_graphics_transfer_e4f5:
    map_graphics_transfer 5, $01EC, $1F
map_graphics_transfer_e4f8:
    map_graphics_transfer 6, $0E0E, $1F
map_graphics_transfer_e4fb:
    map_graphics_transfer 6, $0E21, $1F
map_graphics_transfer_e4fe:
    map_graphics_transfer 5, $010F, $3F
map_graphics_transfer_e501:
    map_graphics_transfer 5, $0144, $0F
map_graphics_transfer_e504:
    map_graphics_transfer 4, $0153, $0F
map_graphics_transfer_e507:
    map_graphics_transfer 6, $0DF8, $2F
map_graphics_transfer_e50a:
    map_graphics_transfer 6, $08CF, $1F
map_graphics_transfer_e50d:
    map_graphics_transfer 6, $0B10, $4F
map_graphics_transfer_e510:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e513:
    map_graphics_transfer 6, $08E8, $3F
map_graphics_transfer_e516:
    map_graphics_transfer 6, $0924, $1F
map_graphics_transfer_e519:
    map_graphics_transfer 6, $093F, $DE
map_graphics_transfer_e51c:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e51f:
    map_graphics_transfer 4, $015D, $4F
map_graphics_transfer_e522:
    map_graphics_transfer 4, $019C, $4F
map_graphics_transfer_e525:
    map_graphics_transfer 5, $01EC, $1F
map_graphics_transfer_e528:
    map_graphics_transfer 6, $0E0E, $1F
map_graphics_transfer_e52b:
    map_graphics_transfer 6, $0E21, $CF
map_graphics_transfer_e52e:
    map_graphics_transfer 6, $0517, $2F
map_graphics_transfer_e531:
    map_graphics_transfer 4, $020A, $1F
map_graphics_transfer_e534:
    map_graphics_transfer 6, $0BC5, $1F
map_graphics_transfer_e537:
    map_graphics_transfer 6, $0BE1, $1F
map_graphics_transfer_e53a:
    map_graphics_transfer 6, $0BF3, $1F
map_graphics_transfer_e53d:
    map_graphics_transfer 6, $0C09, $1F
map_graphics_transfer_e540:
    map_graphics_transfer 6, $0C25, $1F
map_graphics_transfer_e543:
    map_graphics_transfer 6, $0C42, $1F
map_graphics_transfer_e546:
    map_graphics_transfer 6, $0CAF, $9E
map_graphics_transfer_e549:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e54c:
    map_graphics_transfer 6, $0E41, $1F
map_graphics_transfer_e54f:
    map_graphics_transfer 4, $022A, $1F
map_graphics_transfer_e552:
    map_graphics_transfer 6, $0E5F, $3F
map_graphics_transfer_e555:
    map_graphics_transfer 4, $0245, $1B
map_graphics_transfer_e558:
    map_graphics_transfer 5, $0258, $03
map_graphics_transfer_e55b:
    map_graphics_transfer 6, $0E8A, $DF
map_graphics_transfer_e55e:
    map_graphics_transfer 6, $0800, $7F
map_graphics_transfer_e561:
    map_graphics_transfer 6, $0BC5, $1F
map_graphics_transfer_e564:
    map_graphics_transfer 6, $0BE1, $1F
map_graphics_transfer_e567:
    map_graphics_transfer 6, $0C09, $1F
map_graphics_transfer_e56a:
    map_graphics_transfer 6, $0C25, $1F
map_graphics_transfer_e56d:
    map_graphics_transfer 6, $08A0, $1F
map_graphics_transfer_e570:
    map_graphics_transfer 6, $0CAF, $BE
map_graphics_transfer_e573:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e576:
    map_graphics_transfer 6, $1174, $1F
map_graphics_transfer_e579:
    map_graphics_transfer 5, $0336, $1F
map_graphics_transfer_e57c:
    map_graphics_transfer 6, $1193, $0F
map_graphics_transfer_e57f:
    map_graphics_transfer 4, $01AC, $3F
map_graphics_transfer_e582:
    map_graphics_transfer 6, $0AD5, $2F
map_graphics_transfer_e585:
    map_graphics_transfer 6, $081A, $3F
map_graphics_transfer_e588:
    map_graphics_transfer 5, $010F, $3F
map_graphics_transfer_e58b:
    map_graphics_transfer 5, $0144, $0F
map_graphics_transfer_e58e:
    map_graphics_transfer 4, $0153, $0F
map_graphics_transfer_e591:
    map_graphics_transfer 6, $0DF8, $1F
map_graphics_transfer_e594:
    map_graphics_transfer 6, $1F40, $1F
map_graphics_transfer_e597:
    map_graphics_transfer 6, $08CF, $1F
map_graphics_transfer_e59a:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e59d:
    map_graphics_transfer 4, $0034, $01
map_graphics_transfer_e5a0:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e5a3:
    map_graphics_transfer 4, $0036, $0E
map_graphics_transfer_e5a6:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e5a9:
    map_graphics_transfer 4, $0045, $0B
map_graphics_transfer_e5ac:
    map_graphics_transfer 6, $09FA, $1F
map_graphics_transfer_e5af:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e5b2:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e5b5:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e5b8:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e5bb:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e5be:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e5c1:
    map_graphics_transfer 6, $173A, $1F
map_graphics_transfer_e5c4:
    map_graphics_transfer 6, $0ABD, $7E
map_graphics_transfer_e5c7:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e5ca:
    map_graphics_transfer 6, $08CF, $1F
map_graphics_transfer_e5cd:
    map_graphics_transfer 6, $08E8, $3F
map_graphics_transfer_e5d0:
    map_graphics_transfer 6, $0924, $1F
map_graphics_transfer_e5d3:
    map_graphics_transfer 6, $093F, $7F
map_graphics_transfer_e5d6:
    map_graphics_transfer 6, $0B10, $4F
map_graphics_transfer_e5d9:
    map_graphics_transfer 6, $0B55, $2F
map_graphics_transfer_e5dc:
    map_graphics_transfer 5, $010F, $3F
map_graphics_transfer_e5df:
    map_graphics_transfer 5, $0144, $0F
map_graphics_transfer_e5e2:
    map_graphics_transfer 4, $0153, $0F
map_graphics_transfer_e5e5:
    map_graphics_transfer 6, $0DF8, $1F
map_graphics_transfer_e5e8:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e5eb:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e5ee:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e5f1:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e5f4:
    map_graphics_transfer 4, $0034, $01
map_graphics_transfer_e5f7:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e5fa:
    map_graphics_transfer 4, $0036, $0E
map_graphics_transfer_e5fd:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e600:
    map_graphics_transfer 4, $0045, $0B
map_graphics_transfer_e603:
    map_graphics_transfer 6, $09FA, $1F
map_graphics_transfer_e606:
    map_graphics_transfer 6, $0A8C, $5F
map_graphics_transfer_e609:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e60c:
    map_graphics_transfer 6, $09B3, $3E
map_graphics_transfer_e60f:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e612:
    map_graphics_transfer 6, $17A9, $1F
map_graphics_transfer_e615:
    map_graphics_transfer 6, $08E8, $3F
map_graphics_transfer_e618:
    map_graphics_transfer 6, $0924, $1F
map_graphics_transfer_e61b:
    map_graphics_transfer 6, $093F, $7F
map_graphics_transfer_e61e:
    map_graphics_transfer 6, $0B10, $4F
map_graphics_transfer_e621:
    map_graphics_transfer 6, $0B55, $AF
map_graphics_transfer_e624:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e627:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e62a:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e62d:
    map_graphics_transfer 6, $17C4, $1F
map_graphics_transfer_e630:
    map_graphics_transfer 6, $17E4, $1F
map_graphics_transfer_e633:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e636:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_e639:
    map_graphics_transfer 6, $09BF, $0F
map_graphics_transfer_e63c:
    map_graphics_transfer 6, $09CF, $0F
map_graphics_transfer_e63f:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e642:
    map_graphics_transfer 6, $09B3, $0F
map_graphics_transfer_e645:
    map_graphics_transfer 6, $0AFA, $1F
map_graphics_transfer_e648:
    map_graphics_transfer 6, $0AF1, $0E
map_graphics_transfer_e64b:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e64e:
    map_graphics_transfer 6, $0F2A, $02
map_graphics_transfer_e651:
    map_graphics_transfer 4, $025C, $0C
map_graphics_transfer_e654:
    map_graphics_transfer 4, $0264, $01
map_graphics_transfer_e657:
    map_graphics_transfer 5, $0266, $00
map_graphics_transfer_e65a:
    map_graphics_transfer 4, $0267, $08
map_graphics_transfer_e65d:
    map_graphics_transfer 5, $0270, $93
map_graphics_transfer_e660:
    map_graphics_transfer 6, $0F2C, $3F
map_graphics_transfer_e663:
    map_graphics_transfer 6, $0F6C, $1F
map_graphics_transfer_e666:
    map_graphics_transfer 6, $0F8B, $1C
map_graphics_transfer_e669:
    map_graphics_transfer 6, $0FA7, $02
map_graphics_transfer_e66c:
    map_graphics_transfer 6, $0FAA, $0F
map_graphics_transfer_e66f:
    map_graphics_transfer 6, $0FBA, $6F
map_graphics_transfer_e672:
    map_graphics_transfer 6, $1025, $1F
map_graphics_transfer_e675:
    map_graphics_transfer 6, $1045, $0F
map_graphics_transfer_e678:
    map_graphics_transfer 6, $104F, $0F
map_graphics_transfer_e67b:
    map_graphics_transfer 6, $105D, $0F
map_graphics_transfer_e67e:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e681:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e684:
    map_graphics_transfer 6, $1174, $1F
map_graphics_transfer_e687:
    map_graphics_transfer 5, $0336, $1F
map_graphics_transfer_e68a:
    map_graphics_transfer 6, $1193, $0F
map_graphics_transfer_e68d:
    map_graphics_transfer 6, $0000, $0F
map_graphics_transfer_e690:
    map_graphics_transfer 6, $1069, $2F
map_graphics_transfer_e693:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e696:
    map_graphics_transfer 4, $0034, $01
map_graphics_transfer_e699:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e69c:
    map_graphics_transfer 4, $0036, $0E
map_graphics_transfer_e69f:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e6a2:
    map_graphics_transfer 4, $0045, $0B
map_graphics_transfer_e6a5:
    map_graphics_transfer 6, $09FA, $2F
map_graphics_transfer_e6a8:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e6ab:
    map_graphics_transfer 6, $0AD5, $1E
map_graphics_transfer_e6ae:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e6b1:
    map_graphics_transfer 6, $1090, $FF
map_graphics_transfer_e6b4:
    map_graphics_transfer 6, $1190, $0F
map_graphics_transfer_e6b7:
    map_graphics_transfer 6, $1165, $0F
map_graphics_transfer_e6ba:
    map_graphics_transfer 6, $17F4, $DF
map_graphics_transfer_e6bd:
    map_graphics_transfer 6, $0BC5, $1F
map_graphics_transfer_e6c0:
    map_graphics_transfer 6, $0BF3, $1F
map_graphics_transfer_e6c3:
    map_graphics_transfer 6, $0C09, $1F
map_graphics_transfer_e6c6:
    map_graphics_transfer 6, $0C25, $1F
map_graphics_transfer_e6c9:
    map_graphics_transfer 6, $0C42, $1F
map_graphics_transfer_e6cc:
    map_graphics_transfer 6, $1025, $1F
map_graphics_transfer_e6cf:
    map_graphics_transfer 6, $1045, $0F
map_graphics_transfer_e6d2:
    map_graphics_transfer 6, $104F, $2F
map_graphics_transfer_e6d5:
    map_graphics_transfer 5, $0307, $03
map_graphics_transfer_e6d8:
    map_graphics_transfer 4, $0307, $0B
map_graphics_transfer_e6db:
    map_graphics_transfer 6, $1FFB, $4E
map_graphics_transfer_e6de:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e6e1:
    map_graphics_transfer 6, $1174, $1F
map_graphics_transfer_e6e4:
    map_graphics_transfer 5, $0336, $1F
map_graphics_transfer_e6e7:
    map_graphics_transfer 6, $1193, $4F
map_graphics_transfer_e6ea:
    map_graphics_transfer 6, $119D, $6F
map_graphics_transfer_e6ed:
    map_graphics_transfer 4, $0355, $2F
map_graphics_transfer_e6f0:
    map_graphics_transfer 5, $0360, $0F
map_graphics_transfer_e6f3:
    map_graphics_transfer 6, $11AD, $2F
map_graphics_transfer_e6f6:
    map_graphics_transfer 6, $11DC, $1D
map_graphics_transfer_e6f9:
    map_graphics_transfer 6, $1FFF, $01
map_graphics_transfer_e6fc:
    map_graphics_transfer 6, $11FA, $6F
map_graphics_transfer_e6ff:
    map_graphics_transfer 6, $0CEE, $4F
map_graphics_transfer_e702:
    map_graphics_transfer 6, $1212, $3F
map_graphics_transfer_e705:
    map_graphics_transfer 6, $1FF6, $1F
map_graphics_transfer_e708:
    map_graphics_transfer 6, $08A0, $1F
map_graphics_transfer_e70b:
    map_graphics_transfer 6, $0D3A, $8E
map_graphics_transfer_e70e:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e711:
    map_graphics_transfer 6, $0F2A, $02
map_graphics_transfer_e714:
    map_graphics_transfer 4, $025C, $0C
map_graphics_transfer_e717:
    map_graphics_transfer 5, $0274, $1F
map_graphics_transfer_e71a:
    map_graphics_transfer 6, $0F2C, $3F
map_graphics_transfer_e71d:
    map_graphics_transfer 6, $0FBA, $6F
map_graphics_transfer_e720:
    map_graphics_transfer 6, $1025, $1F
map_graphics_transfer_e723:
    map_graphics_transfer 6, $18EC, $1F
map_graphics_transfer_e726:
    map_graphics_transfer 6, $19D5, $0F
map_graphics_transfer_e729:
    map_graphics_transfer 6, $19E5, $1F
map_graphics_transfer_e72c:
    map_graphics_transfer 6, $162E, $6F
map_graphics_transfer_e72f:
    map_graphics_transfer 6, $1916, $1F
map_graphics_transfer_e732:
    map_graphics_transfer 6, $1931, $1F
map_graphics_transfer_e735:
    map_graphics_transfer 6, $0F8B, $1C
map_graphics_transfer_e738:
    map_graphics_transfer 6, $0FA7, $02
map_graphics_transfer_e73b:
    map_graphics_transfer 5, $0481, $1F
map_graphics_transfer_e73e:
    map_graphics_transfer 6, $1958, $5F
map_graphics_transfer_e741:
    map_graphics_transfer 6, $1F29, $0F
map_graphics_transfer_e744:
    map_graphics_transfer 5, $010F, $3F
map_graphics_transfer_e747:
    map_graphics_transfer 5, $0144, $0F
map_graphics_transfer_e74a:
    map_graphics_transfer 4, $0153, $0F
map_graphics_transfer_e74d:
    map_graphics_transfer 6, $0DF8, $1F
map_graphics_transfer_e750:
    map_graphics_transfer 6, $104F, $0F
map_graphics_transfer_e753:
    map_graphics_transfer 6, $0A3A, $1E
map_graphics_transfer_e756:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e759:
    map_graphics_transfer 6, $124F, $FF
map_graphics_transfer_e75c:
    map_graphics_transfer 6, $134F, $0F
map_graphics_transfer_e75f:
    map_graphics_transfer 4, $0370, $03
map_graphics_transfer_e762:
    map_graphics_transfer 5, $0374, $1B
map_graphics_transfer_e765:
    map_graphics_transfer 4, $0390, $2F
map_graphics_transfer_e768:
    map_graphics_transfer 6, $1347, $5F
map_graphics_transfer_e76b:
    map_graphics_transfer 6, $1F60, $3F
map_graphics_transfer_e76e:
    map_graphics_transfer 6, $0A11, $3F
map_graphics_transfer_e771:
    map_graphics_transfer 6, $1B3D, $1F
map_graphics_transfer_e774:
    map_graphics_transfer 6, $1F97, $4F
map_graphics_transfer_e777:
    map_graphics_transfer 6, $1FE6, $0F
map_graphics_transfer_e77a:
    map_graphics_transfer 6, $0D3A, $9E
map_graphics_transfer_e77d:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e780:
    map_graphics_transfer 6, $13A3, $FF
map_graphics_transfer_e783:
    map_graphics_transfer 6, $0800, $FF
map_graphics_transfer_e786:
    map_graphics_transfer 6, $0BC5, $1F
map_graphics_transfer_e789:
    map_graphics_transfer 6, $0BE1, $1F
map_graphics_transfer_e78c:
    map_graphics_transfer 6, $0BF3, $1F
map_graphics_transfer_e78f:
    map_graphics_transfer 6, $0C09, $FE
map_graphics_transfer_e792:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e795:
    map_graphics_transfer 6, $1449, $FF
map_graphics_transfer_e798:
    map_graphics_transfer 6, $1549, $FF
map_graphics_transfer_e79b:
    map_graphics_transfer 4, $0370, $03
map_graphics_transfer_e79e:
    map_graphics_transfer 5, $0374, $1B
map_graphics_transfer_e7a1:
    map_graphics_transfer 4, $0390, $1F
map_graphics_transfer_e7a4:
    map_graphics_transfer 6, $0800, $BF
map_graphics_transfer_e7a7:
    map_graphics_transfer 6, $0800, $5E
map_graphics_transfer_e7aa:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e7ad:
    map_graphics_transfer 6, $1449, $FF
map_graphics_transfer_e7b0:
    map_graphics_transfer 6, $1549, $FF
map_graphics_transfer_e7b3:
    map_graphics_transfer 6, $0800, $FF
map_graphics_transfer_e7b6:
    map_graphics_transfer 6, $0800, $5E
map_graphics_transfer_e7b9:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e7bc:
    map_graphics_transfer 6, $15C2, $5F
map_graphics_transfer_e7bf:
    map_graphics_transfer 6, $1613, $1F
map_graphics_transfer_e7c2:
    map_graphics_transfer 6, $162E, $5F
map_graphics_transfer_e7c5:
    map_graphics_transfer 6, $1682, $1F
map_graphics_transfer_e7c8:
    map_graphics_transfer 6, $16A2, $1F
map_graphics_transfer_e7cb:
    map_graphics_transfer 6, $16C1, $CF
map_graphics_transfer_e7ce:
    map_graphics_transfer 6, $1FE6, $0F
map_graphics_transfer_e7d1:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e7d4:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e7d7:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e7da:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e7dd:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e7e0:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e7e3:
    map_graphics_transfer 6, $173A, $1F
map_graphics_transfer_e7e6:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_e7e9:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e7ec:
    map_graphics_transfer 6, $0AF1, $0F
map_graphics_transfer_e7ef:
    map_graphics_transfer 6, $0AFA, $2E
map_graphics_transfer_e7f2:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e7f5:
    map_graphics_transfer 6, $15C2, $5F
map_graphics_transfer_e7f8:
    map_graphics_transfer 6, $1613, $1F
map_graphics_transfer_e7fb:
    map_graphics_transfer 6, $162E, $5F
map_graphics_transfer_e7fe:
    map_graphics_transfer 6, $1682, $1F
map_graphics_transfer_e801:
    map_graphics_transfer 6, $16A2, $1F
map_graphics_transfer_e804:
    map_graphics_transfer 6, $16C1, $CF
map_graphics_transfer_e807:
    map_graphics_transfer 6, $1FE6, $0F
map_graphics_transfer_e80a:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e80d:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e810:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e813:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e816:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e819:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e81c:
    map_graphics_transfer 6, $173A, $1F
map_graphics_transfer_e81f:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_e822:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e825:
    map_graphics_transfer 6, $0AF1, $0F
map_graphics_transfer_e828:
    map_graphics_transfer 6, $0AFA, $2E
map_graphics_transfer_e82b:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e82e:
    map_graphics_transfer 4, $03AB, $0F
map_graphics_transfer_e831:
    map_graphics_transfer 4, $03B3, $00
map_graphics_transfer_e834:
    map_graphics_transfer 5, $03B4, $0F
map_graphics_transfer_e837:
    map_graphics_transfer 4, $03C4, $01
map_graphics_transfer_e83a:
    map_graphics_transfer 5, $03C6, $10
map_graphics_transfer_e83d:
    map_graphics_transfer 4, $03D7, $0B
map_graphics_transfer_e840:
    map_graphics_transfer 6, $1A8B, $BF
map_graphics_transfer_e843:
    map_graphics_transfer 4, $0000, $0F
map_graphics_transfer_e846:
    map_graphics_transfer 6, $09B3, $0F
map_graphics_transfer_e849:
    map_graphics_transfer 6, $09BF, $0F
map_graphics_transfer_e84c:
    map_graphics_transfer 6, $09CF, $0F
map_graphics_transfer_e84f:
    map_graphics_transfer 4, $0010, $2F
map_graphics_transfer_e852:
    map_graphics_transfer 6, $09DB, $0F
map_graphics_transfer_e855:
    map_graphics_transfer 6, $09DF, $3F
map_graphics_transfer_e858:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e85b:
    map_graphics_transfer 4, $0034, $01
map_graphics_transfer_e85e:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e861:
    map_graphics_transfer 4, $0036, $0E
map_graphics_transfer_e864:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e867:
    map_graphics_transfer 4, $0045, $0B
map_graphics_transfer_e86a:
    map_graphics_transfer 6, $09FA, $1F
map_graphics_transfer_e86d:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e870:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e873:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e876:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e879:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e87c:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e87f:
    map_graphics_transfer 6, $0AA6, $1F
map_graphics_transfer_e882:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_e885:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e888:
    map_graphics_transfer 6, $0AF1, $0F
map_graphics_transfer_e88b:
    map_graphics_transfer 6, $0AFA, $2E
map_graphics_transfer_e88e:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e891:
    map_graphics_transfer 4, $0566, $1F
map_graphics_transfer_e894:
    map_graphics_transfer 6, $1A14, $9F
map_graphics_transfer_e897:
    map_graphics_transfer 6, $08A0, $3F
map_graphics_transfer_e89a:
    map_graphics_transfer 4, $0000, $0F
map_graphics_transfer_e89d:
    map_graphics_transfer 6, $09B3, $0F
map_graphics_transfer_e8a0:
    map_graphics_transfer 6, $09BF, $0F
map_graphics_transfer_e8a3:
    map_graphics_transfer 6, $09CF, $8F
map_graphics_transfer_e8a6:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e8a9:
    map_graphics_transfer 4, $0034, $01
map_graphics_transfer_e8ac:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e8af:
    map_graphics_transfer 4, $0036, $0E
map_graphics_transfer_e8b2:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e8b5:
    map_graphics_transfer 4, $0045, $0B
map_graphics_transfer_e8b8:
    map_graphics_transfer 6, $09FA, $1F
map_graphics_transfer_e8bb:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e8be:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e8c1:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e8c4:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e8c7:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e8ca:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e8cd:
    map_graphics_transfer 6, $173A, $1F
map_graphics_transfer_e8d0:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_e8d3:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e8d6:
    map_graphics_transfer 6, $0AF1, $0F
map_graphics_transfer_e8d9:
    map_graphics_transfer 6, $0AFA, $2E
map_graphics_transfer_e8dc:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e8df:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e8e2:
    map_graphics_transfer 5, $03E2, $03
map_graphics_transfer_e8e5:
    map_graphics_transfer 4, $03E6, $0A
map_graphics_transfer_e8e8:
    map_graphics_transfer 5, $03F1, $1B
map_graphics_transfer_e8eb:
    map_graphics_transfer 4, $040D, $07
map_graphics_transfer_e8ee:
    map_graphics_transfer 5, $0415, $1B
map_graphics_transfer_e8f1:
    map_graphics_transfer 4, $0431, $12
map_graphics_transfer_e8f4:
    map_graphics_transfer 6, $175A, $00
map_graphics_transfer_e8f7:
    map_graphics_transfer 5, $0444, $0B
map_graphics_transfer_e8fa:
    map_graphics_transfer 4, $0450, $05
map_graphics_transfer_e8fd:
    map_graphics_transfer 5, $0456, $09
map_graphics_transfer_e900:
    map_graphics_transfer 4, $0460, $07
map_graphics_transfer_e903:
    map_graphics_transfer 5, $0468, $03
map_graphics_transfer_e906:
    map_graphics_transfer 4, $046C, $03
map_graphics_transfer_e909:
    map_graphics_transfer 6, $175B, $6F
map_graphics_transfer_e90c:
    map_graphics_transfer 6, $0800, $FF
map_graphics_transfer_e90f:
    map_graphics_transfer 6, $0800, $FF
map_graphics_transfer_e912:
    map_graphics_transfer 6, $0800, $5E
map_graphics_transfer_e915:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e918:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e91b:
    map_graphics_transfer 4, $04AC, $5E
map_graphics_transfer_e91e:
    map_graphics_transfer 5, $04FB, $1F
map_graphics_transfer_e921:
    map_graphics_transfer 5, $0517, $1F
map_graphics_transfer_e924:
    map_graphics_transfer 5, $0537, $3F
map_graphics_transfer_e927:
    map_graphics_transfer 6, $19FF, $1F
map_graphics_transfer_e92a:
    map_graphics_transfer 6, $16A2, $1F
map_graphics_transfer_e92d:
    map_graphics_transfer 6, $1682, $1F
map_graphics_transfer_e930:
    map_graphics_transfer 6, $0800, $FF
map_graphics_transfer_e933:
    map_graphics_transfer 6, $0E21, $1F
map_graphics_transfer_e936:
    map_graphics_transfer 4, $015D, $4F
map_graphics_transfer_e939:
    map_graphics_transfer 4, $019C, $7F
map_graphics_transfer_e93c:
    map_graphics_transfer 6, $0AFA, $2E
map_graphics_transfer_e93f:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e942:
    map_graphics_transfer 6, $0800, $FF
map_graphics_transfer_e945:
    map_graphics_transfer 6, $17D4, $FF
map_graphics_transfer_e948:
    map_graphics_transfer 6, $0800, $FF
map_graphics_transfer_e94b:
    map_graphics_transfer 6, $0800, $5E
map_graphics_transfer_e94e:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e951:
    map_graphics_transfer 6, $1174, $1F
map_graphics_transfer_e954:
    map_graphics_transfer 5, $0336, $1F
map_graphics_transfer_e957:
    map_graphics_transfer 6, $1193, $0F
map_graphics_transfer_e95a:
    map_graphics_transfer 6, $18D4, $1F
map_graphics_transfer_e95d:
    map_graphics_transfer 6, $18EC, $1F
map_graphics_transfer_e960:
    map_graphics_transfer 6, $1F29, $0F
map_graphics_transfer_e963:
    map_graphics_transfer 6, $190B, $2F
map_graphics_transfer_e966:
    map_graphics_transfer 6, $1916, $1F
map_graphics_transfer_e969:
    map_graphics_transfer 6, $1931, $1F
map_graphics_transfer_e96c:
    map_graphics_transfer 6, $1944, $1F
map_graphics_transfer_e96f:
    map_graphics_transfer 5, $0481, $1F
map_graphics_transfer_e972:
    map_graphics_transfer 6, $1958, $5F
map_graphics_transfer_e975:
    map_graphics_transfer 6, $19B5, $1F
map_graphics_transfer_e978:
    map_graphics_transfer 6, $19D5, $0F
map_graphics_transfer_e97b:
    map_graphics_transfer 6, $19E5, $1F
map_graphics_transfer_e97e:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_e981:
    map_graphics_transfer 6, $162E, $5F
map_graphics_transfer_e984:
    map_graphics_transfer 6, $0924, $1F
map_graphics_transfer_e987:
    map_graphics_transfer 6, $0A3A, $3F
map_graphics_transfer_e98a:
    map_graphics_transfer 6, $11FA, $7E
map_graphics_transfer_e98d:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e990:
    map_graphics_transfer 6, $15C2, $5F
map_graphics_transfer_e993:
    map_graphics_transfer 6, $1613, $1F
map_graphics_transfer_e996:
    map_graphics_transfer 6, $162E, $5F
map_graphics_transfer_e999:
    map_graphics_transfer 6, $1682, $1F
map_graphics_transfer_e99c:
    map_graphics_transfer 6, $16A2, $1F
map_graphics_transfer_e99f:
    map_graphics_transfer 6, $16C1, $9F
map_graphics_transfer_e9a2:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e9a5:
    map_graphics_transfer 4, $0034, $01
map_graphics_transfer_e9a8:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e9ab:
    map_graphics_transfer 4, $0036, $0E
map_graphics_transfer_e9ae:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e9b1:
    map_graphics_transfer 4, $0045, $0B
map_graphics_transfer_e9b4:
    map_graphics_transfer 6, $09FA, $1F
map_graphics_transfer_e9b7:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e9ba:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e9bd:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e9c0:
    map_graphics_transfer 6, $08E8, $3F
map_graphics_transfer_e9c3:
    map_graphics_transfer 6, $0924, $1F
map_graphics_transfer_e9c6:
    map_graphics_transfer 6, $093F, $7F
map_graphics_transfer_e9c9:
    map_graphics_transfer 6, $0AD5, $1E
map_graphics_transfer_e9cc:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_e9cf:
    map_graphics_transfer 4, $0566, $1F
map_graphics_transfer_e9d2:
    map_graphics_transfer 6, $1A14, $9F
map_graphics_transfer_e9d5:
    map_graphics_transfer 6, $08A0, $3F
map_graphics_transfer_e9d8:
    map_graphics_transfer 4, $0000, $0F
map_graphics_transfer_e9db:
    map_graphics_transfer 6, $09B3, $0F
map_graphics_transfer_e9de:
    map_graphics_transfer 6, $09BF, $0F
map_graphics_transfer_e9e1:
    map_graphics_transfer 6, $09CF, $8F
map_graphics_transfer_e9e4:
    map_graphics_transfer 6, $1F60, $3F
map_graphics_transfer_e9e7:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_e9ea:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_e9ed:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_e9f0:
    map_graphics_transfer 6, $0A56, $1F
map_graphics_transfer_e9f3:
    map_graphics_transfer 6, $0A71, $1F
map_graphics_transfer_e9f6:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_e9f9:
    map_graphics_transfer 6, $173A, $1F
map_graphics_transfer_e9fc:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_e9ff:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_ea02:
    map_graphics_transfer 6, $0AF1, $0F
map_graphics_transfer_ea05:
    map_graphics_transfer 6, $0AFA, $2E
map_graphics_transfer_ea08:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_ea0b:
    map_graphics_transfer 6, $15C2, $5F
map_graphics_transfer_ea0e:
    map_graphics_transfer 6, $1613, $1F
map_graphics_transfer_ea11:
    map_graphics_transfer 6, $162E, $5F
map_graphics_transfer_ea14:
    map_graphics_transfer 6, $1682, $1F
map_graphics_transfer_ea17:
    map_graphics_transfer 6, $16A2, $1F
map_graphics_transfer_ea1a:
    map_graphics_transfer 6, $16C1, $9F
map_graphics_transfer_ea1d:
    map_graphics_transfer 6, $1F60, $3F
map_graphics_transfer_ea20:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_ea23:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_ea26:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_ea29:
    map_graphics_transfer 6, $08E8, $3F
map_graphics_transfer_ea2c:
    map_graphics_transfer 6, $0924, $1F
map_graphics_transfer_ea2f:
    map_graphics_transfer 6, $093F, $7F
map_graphics_transfer_ea32:
    map_graphics_transfer 6, $0AD5, $1E
map_graphics_transfer_ea35:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_ea38:
    map_graphics_transfer 4, $015D, $4F
map_graphics_transfer_ea3b:
    map_graphics_transfer 4, $019C, $4F
map_graphics_transfer_ea3e:
    map_graphics_transfer 5, $01EC, $0F
map_graphics_transfer_ea41:
    map_graphics_transfer 5, $057C, $09
map_graphics_transfer_ea44:
    map_graphics_transfer 5, $01FC, $05
map_graphics_transfer_ea47:
    map_graphics_transfer 6, $0E0E, $1F
map_graphics_transfer_ea4a:
    map_graphics_transfer 6, $0E21, $1F
map_graphics_transfer_ea4d:
    map_graphics_transfer 5, $010F, $3F
map_graphics_transfer_ea50:
    map_graphics_transfer 5, $0144, $0F
map_graphics_transfer_ea53:
    map_graphics_transfer 4, $0153, $0F
map_graphics_transfer_ea56:
    map_graphics_transfer 6, $0DF8, $2F
map_graphics_transfer_ea59:
    map_graphics_transfer 6, $08CF, $1F
map_graphics_transfer_ea5c:
    map_graphics_transfer 6, $0B10, $4F
map_graphics_transfer_ea5f:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_ea62:
    map_graphics_transfer 6, $08E8, $3F
map_graphics_transfer_ea65:
    map_graphics_transfer 6, $0924, $1F
map_graphics_transfer_ea68:
    map_graphics_transfer 6, $093F, $DE
map_graphics_transfer_ea6b:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_ea6e:
    map_graphics_transfer 4, $015D, $4F
map_graphics_transfer_ea71:
    map_graphics_transfer 4, $019C, $4F
map_graphics_transfer_ea74:
    map_graphics_transfer 5, $01EC, $0F
map_graphics_transfer_ea77:
    map_graphics_transfer 5, $057C, $09
map_graphics_transfer_ea7a:
    map_graphics_transfer 5, $01FC, $05
map_graphics_transfer_ea7d:
    map_graphics_transfer 6, $0E0E, $1F
map_graphics_transfer_ea80:
    map_graphics_transfer 6, $0E21, $CF
map_graphics_transfer_ea83:
    map_graphics_transfer 6, $0517, $2F
map_graphics_transfer_ea86:
    map_graphics_transfer 4, $020A, $1F
map_graphics_transfer_ea89:
    map_graphics_transfer 6, $0BC5, $1F
map_graphics_transfer_ea8c:
    map_graphics_transfer 6, $0BE1, $1F
map_graphics_transfer_ea8f:
    map_graphics_transfer 6, $0BF3, $1F
map_graphics_transfer_ea92:
    map_graphics_transfer 6, $0C09, $1F
map_graphics_transfer_ea95:
    map_graphics_transfer 6, $0C25, $1F
map_graphics_transfer_ea98:
    map_graphics_transfer 6, $0C42, $1F
map_graphics_transfer_ea9b:
    map_graphics_transfer 6, $0CAF, $9E
map_graphics_transfer_ea9e:
    map_graphics_transfer 0, $0000, $00
map_graphics_transfer_eaa1:
    map_graphics_transfer 6, $08CF, $1F
map_graphics_transfer_eaa4:
    map_graphics_transfer 6, $08E8, $3F
map_graphics_transfer_eaa7:
    map_graphics_transfer 6, $0924, $1F
map_graphics_transfer_eaaa:
    map_graphics_transfer 6, $093F, $7F
map_graphics_transfer_eaad:
    map_graphics_transfer 6, $0B10, $4F
map_graphics_transfer_eab0:
    map_graphics_transfer 6, $0B55, $AF
map_graphics_transfer_eab3:
    map_graphics_transfer 6, $0A11, $1F
map_graphics_transfer_eab6:
    map_graphics_transfer 6, $0A26, $1F
map_graphics_transfer_eab9:
    map_graphics_transfer 6, $0A3A, $1F
map_graphics_transfer_eabc:
    map_graphics_transfer 6, $1F60, $3F
map_graphics_transfer_eabf:
    map_graphics_transfer 6, $0A8C, $1F
map_graphics_transfer_eac2:
    map_graphics_transfer 6, $0ABD, $1F
map_graphics_transfer_eac5:
    map_graphics_transfer 6, $09BF, $0F
map_graphics_transfer_eac8:
    map_graphics_transfer 6, $09CF, $0F
map_graphics_transfer_eacb:
    map_graphics_transfer 6, $0AD5, $1F
map_graphics_transfer_eace:
    map_graphics_transfer 6, $09B3, $0F
map_graphics_transfer_ead1:
    map_graphics_transfer 6, $0AFA, $1F
map_graphics_transfer_ead4:
    map_graphics_transfer 6, $0AF1, $0E
map_graphics_transfer_ead7:
    map_graphics_transfer 0, $0000, $00
