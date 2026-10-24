.setcpu "65816"
.segment "CODE"
.org $3224
map_control_0d3224:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
