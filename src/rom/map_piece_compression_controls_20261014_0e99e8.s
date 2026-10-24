.setcpu "65816"
.segment "CODE"
.org $99E8
map_control_0e99e8:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
