.setcpu "65816"
.segment "CODE"
.org $359A
map_control_0f359a:
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
