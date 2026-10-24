.setcpu "65816"
.segment "CODE"
.org $15AF
map_control_0d15af:
    .byte $E2 ; previous-row copy count
