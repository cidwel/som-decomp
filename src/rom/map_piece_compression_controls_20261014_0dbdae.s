.setcpu "65816"
.segment "CODE"
.org $BDAE
map_control_0dbdae:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
