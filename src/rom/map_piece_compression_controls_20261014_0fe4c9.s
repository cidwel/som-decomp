.setcpu "65816"
.segment "CODE"
.org $E4C9
map_control_0fe4c9:
    .byte $EB ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
