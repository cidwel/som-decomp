.setcpu "65816"
.segment "CODE"
.org $E878
map_control_0ee878:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
