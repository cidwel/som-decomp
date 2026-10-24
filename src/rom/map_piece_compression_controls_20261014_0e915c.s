.setcpu "65816"
.segment "CODE"
.org $915C
map_control_0e915c:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $6D ; distance low bit/count
