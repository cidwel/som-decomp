.setcpu "65816"
.segment "CODE"
.org $6069
map_control_0e6069:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
