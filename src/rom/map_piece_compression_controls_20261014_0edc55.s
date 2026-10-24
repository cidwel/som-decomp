.setcpu "65816"
.segment "CODE"
.org $DC55
map_control_0edc55:
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
