; Numeric sprite control metadata; no graphical payload.
.setcpu "65816"
.segment "RODATA"
.org $603A
warm_child_metadata_603a:
    .byte $09, $12, $09, $00 ; tile-base IDs for states0..3
