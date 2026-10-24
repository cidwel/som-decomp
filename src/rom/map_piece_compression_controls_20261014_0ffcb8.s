.setcpu "65816"
.segment "CODE"
.org $FCB8
map_control_0ffcb8:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
