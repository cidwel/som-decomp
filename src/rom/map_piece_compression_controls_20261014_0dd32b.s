.setcpu "65816"
.segment "CODE"
.org $D32B
map_control_0dd32b:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
