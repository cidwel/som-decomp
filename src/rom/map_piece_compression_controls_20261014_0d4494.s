.setcpu "65816"
.segment "CODE"
.org $4494
map_control_0d4494:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
