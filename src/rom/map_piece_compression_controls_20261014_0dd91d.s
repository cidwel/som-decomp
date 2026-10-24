.setcpu "65816"
.segment "CODE"
.org $D91D
map_control_0dd91d:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
