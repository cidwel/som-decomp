; Actual near code-pointer fields; docs/source-recovery-parallel-latent-scroll-dispatch-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $FFEF
latent_set_scrolling_dialogue_line_indentation = $FE4D
latent_reset_scrolling_dialogue_line_delay = $FE62
latent_begin_scrolling_dialogue_end_sequence = $FE68
latent_advance_scrolling_dialogue_line = $FE74
latent_write_scrolling_dialogue_character_tile = $FE7A
latent_scrolling_dialogue_command_targets:
    .word latent_set_scrolling_dialogue_line_indentation, latent_reset_scrolling_dialogue_line_delay, latent_begin_scrolling_dialogue_end_sequence, latent_advance_scrolling_dialogue_line, latent_write_scrolling_dialogue_character_tile
