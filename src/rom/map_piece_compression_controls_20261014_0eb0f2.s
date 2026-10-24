.setcpu "65816"
.segment "CODE"
.org $B0F2
map_control_0eb0f2:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
