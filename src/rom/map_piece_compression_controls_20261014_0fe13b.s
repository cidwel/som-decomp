.setcpu "65816"
.segment "CODE"
.org $E13B
map_control_0fe13b:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
