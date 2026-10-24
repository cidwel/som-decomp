.setcpu "65816"
.segment "CODE"
.org $6BFD
map_control_0f6bfd:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
