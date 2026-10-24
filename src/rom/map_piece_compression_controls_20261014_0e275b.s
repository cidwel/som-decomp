.setcpu "65816"
.segment "CODE"
.org $275B
map_control_0e275b:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
