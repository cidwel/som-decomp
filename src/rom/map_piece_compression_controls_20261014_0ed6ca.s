.setcpu "65816"
.segment "CODE"
.org $D6CA
map_control_0ed6ca:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
