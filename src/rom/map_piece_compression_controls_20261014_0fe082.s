.setcpu "65816"
.segment "CODE"
.org $E082
map_control_0fe082:
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
