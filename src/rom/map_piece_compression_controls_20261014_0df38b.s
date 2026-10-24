.setcpu "65816"
.segment "CODE"
.org $F38B
map_control_0df38b:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
