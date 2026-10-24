.setcpu "65816"
.segment "CODE"
.org $D17A
map_control_0fd17a:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
