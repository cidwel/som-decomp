.setcpu "65816"
.segment "CODE"
.org $7A26
map_control_0d7a26:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
