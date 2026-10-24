.setcpu "65816"
.segment "CODE"
.org $9012
map_control_0d9012:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
