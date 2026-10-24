.setcpu "65816"
.segment "CODE"
.org $4EAA
map_control_0f4eaa:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
