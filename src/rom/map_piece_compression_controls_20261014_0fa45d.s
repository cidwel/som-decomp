.setcpu "65816"
.segment "CODE"
.org $A45D
map_control_0fa45d:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
