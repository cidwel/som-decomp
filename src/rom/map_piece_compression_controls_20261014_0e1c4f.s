.setcpu "65816"
.segment "CODE"
.org $1C4F
map_control_0e1c4f:
    .byte $E4 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
