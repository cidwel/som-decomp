.setcpu "65816"
.segment "CODE"
.org $2EB2
map_control_0f2eb2:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
