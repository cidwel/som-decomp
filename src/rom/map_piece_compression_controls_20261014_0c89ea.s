.setcpu "65816"
.segment "CODE"
.org $89EA
map_control_0c89ea:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
