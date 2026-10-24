.setcpu "65816"
.segment "CODE"
.org $0926
map_control_0d0926:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
