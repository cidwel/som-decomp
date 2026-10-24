.setcpu "65816"
.segment "CODE"
.org $AA7B
map_control_0faa7b:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
