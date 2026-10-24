.setcpu "65816"
.segment "CODE"
.org $39C5
map_control_0d39c5:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
