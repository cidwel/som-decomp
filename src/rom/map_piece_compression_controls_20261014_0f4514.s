.setcpu "65816"
.segment "CODE"
.org $4514
map_control_0f4514:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
