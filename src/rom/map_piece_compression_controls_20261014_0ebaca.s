.setcpu "65816"
.segment "CODE"
.org $BACA
map_control_0ebaca:
    .byte $E1 ; previous-row copy count
