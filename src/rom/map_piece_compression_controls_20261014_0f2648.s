.setcpu "65816"
.segment "CODE"
.org $2648
map_control_0f2648:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
