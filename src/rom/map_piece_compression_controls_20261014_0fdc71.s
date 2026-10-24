.setcpu "65816"
.segment "CODE"
.org $DC71
map_control_0fdc71:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
