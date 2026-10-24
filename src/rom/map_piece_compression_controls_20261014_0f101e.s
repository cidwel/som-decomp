.setcpu "65816"
.segment "CODE"
.org $101E
map_control_0f101e:
    .byte $E0 ; previous-row copy escape
    .byte $57 ; row-distance/count
