.setcpu "65816"
.segment "CODE"
.org $1725
map_control_0d1725:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
