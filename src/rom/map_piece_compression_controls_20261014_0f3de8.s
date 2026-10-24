.setcpu "65816"
.segment "CODE"
.org $3DE8
map_control_0f3de8:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
