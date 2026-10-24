.setcpu "65816"
.segment "CODE"
.org $7912
map_control_0e7912:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
