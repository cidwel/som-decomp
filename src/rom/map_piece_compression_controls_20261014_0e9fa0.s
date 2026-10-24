.setcpu "65816"
.segment "CODE"
.org $9FA0
map_control_0e9fa0:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
