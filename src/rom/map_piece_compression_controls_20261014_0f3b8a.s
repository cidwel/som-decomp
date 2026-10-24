.setcpu "65816"
.segment "CODE"
.org $3B8A
map_control_0f3b8a:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
