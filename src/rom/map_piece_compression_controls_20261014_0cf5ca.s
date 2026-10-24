.setcpu "65816"
.segment "CODE"
.org $F5CA
map_control_0cf5ca:
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
