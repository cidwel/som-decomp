.setcpu "65816"
.segment "CODE"
.org $AEE5
map_control_0eaee5:
    .byte $E9 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
