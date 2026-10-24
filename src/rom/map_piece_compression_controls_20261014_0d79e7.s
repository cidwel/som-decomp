.setcpu "65816"
.segment "CODE"
.org $79E7
map_control_0d79e7:
    .byte $EA ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
