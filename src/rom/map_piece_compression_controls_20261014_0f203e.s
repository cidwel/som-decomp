.setcpu "65816"
.segment "CODE"
.org $203E
map_control_0f203e:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
