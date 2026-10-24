.setcpu "65816"
.segment "CODE"
.org $DD6B
map_control_0edd6b:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5B ; row-distance/count
