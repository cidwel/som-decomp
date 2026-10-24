.setcpu "65816"
.segment "CODE"
.org $4719
map_control_0f4719:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $58 ; distance low bit/count
