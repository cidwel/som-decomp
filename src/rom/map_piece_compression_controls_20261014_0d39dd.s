.setcpu "65816"
.segment "CODE"
.org $39DD
map_control_0d39dd:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
