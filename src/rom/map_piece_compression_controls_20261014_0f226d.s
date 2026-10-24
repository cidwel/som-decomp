.setcpu "65816"
.segment "CODE"
.org $226D
map_control_0f226d:
    .byte $EA ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
