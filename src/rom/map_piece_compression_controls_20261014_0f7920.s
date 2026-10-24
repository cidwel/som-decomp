.setcpu "65816"
.segment "CODE"
.org $7920
map_control_0f7920:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
