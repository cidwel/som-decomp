.setcpu "65816"
.segment "CODE"
.org $B40E
map_control_0eb40e:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
